#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intal.h"

struct intarblen
{
	short int *arr;
	int size;

};

typedef struct intarblen* inlat;
double time_elapsed(struct timespec *start,struct timespec *end);
inlat KA(void* intal1,void* intal2);
void remove_pre_zeroes(inlat* temp);
void* add_pre_zeroes(void* intal,int diff);

void* intal_create(const char* str)
{
	inlat temp=(inlat)malloc(sizeof(struct intarblen));
	int i=0;
	if(strcmp(str,"NaN")==0) return NULL;
	temp->arr=(short int*)malloc(strlen(str)*sizeof(short int));
	temp->size=strlen(str);
	int j=0;
	if(temp->arr!=NULL)
	{
		while(str[i]!='\0')
		{
			if(str[i]-'0'>=0 && str[i]-'0'<=9)
			{
				temp->arr[j]=str[i]-'0';
				j++;
			}
			i++;
		}
	}
	if(j==0||temp->arr==NULL) return NULL;
	return temp;
}

void intal_destroy(void* intal)
{
	inlat temp=(inlat)intal;
	free(temp->arr);
	temp->arr=NULL;
	free(temp);
	temp=NULL;
}

char* intal2str(void* intal)
{
	inlat temp=(inlat)intal;
	if(temp!=NULL)
	{
		char *n=(char*)malloc(sizeof(char)*((temp->size)+1));//1 for null character
		for(int i=0;i<temp->size;i++)
		{
			n[i]=temp->arr[i]+'0';
		}
		n[temp->size]='\0';
		return n;	
	}
	else
	{
		char *n=(char*)malloc(sizeof(char)*4);//1 for null character
		n[0]='N';
		n[1]='a';
		n[2]='N';
		n[3]='\0';
		return n;
	}
	
}

void* add_pre_zeroes(void* intal,int diff)
{
	if(diff==0) return intal;
	inlat temp=(inlat)intal;
	/*for(int i=0;i<temp->size;i++)
		printf("%d\n",temp->arr[i]);
	printf("\n");*/
	if(temp==NULL) return NULL;
	inlat newint=(inlat)malloc(sizeof(struct intarblen));

	newint->size=temp->size+diff;
	//printf("%d\n",newint->size);
	newint->arr=(short int*)malloc(newint->size*sizeof(short int));
	for(int i=0;i<diff;i++)
	{
		newint->arr[i]=0;
	}
	int j=0;
	for(int i=diff;i<newint->size;i++)
	{
		newint->arr[i]=temp->arr[j];
		j++;
	}
	//intal_destroy(temp);
	return newint;
}

void remove_pre_zeroes(inlat* temp)
{
	if((*temp)->size==1 && (*temp)->arr[0]==0) return;
	int i,count=0;

	for(i=0;i<(*temp)->size;i++)
	{
		if((*temp)->arr[i]==0) count++;
		else break;
	}
	if(count==(*temp)->size)
	{
		(*temp)->arr+=count-1;
		(*temp)->size-=count-1;
		return;
	}
	else
	{
		(*temp)->arr+=count;
		(*temp)->size-=count;
	}
}

void* intal_increment(void* intal)
{
	
	void *temp_intal,*ti;
	inlat temp;
	temp_intal=intal_create(intal2str(intal));
	temp = (inlat)temp_intal;
	// printf("Entered intal_increment\n");
	int i=temp->size-1;
	while(temp->arr[i]==9 && i>0)
	{
		temp->arr[i]=0;
		i--;
	}
	//border case like 9999 where the size of the array has to increase by 1
	if(temp->arr[i]==9 && i==0)
	{
		char *str=(char*)malloc((temp->size+2)*sizeof(char));//2=(1 for extra digit)+(1 for null char)
		int j=0;str[j]='1';
		for(j=1;j<=temp->size;j++)
		{
			str[j]='0';
		}
		str[j]='\0';
		ti=intal_create(str);
		intal_destroy(temp_intal);//destroy intal only when the size changes
		return ti;
	}
	if(temp->arr[i]!=9)
		(temp->arr[i])+=1;
	return temp;
}

void* intal_decrement(void* intal)
{
	// printf("Entered intal_decrement\n");
	void *temp_intal,*ti;
	inlat temp;
	temp_intal=intal_create(intal2str(intal));
	temp = (inlat)temp_intal;

	if(temp->size==1)//handling if intal is single digit
	{	if(temp->arr[0]==0)// if intal=0
			return temp;
		else
		{
			(temp->arr[0])-=1;
			return temp;
		}
	}

	int i=temp->size-1;
	while(temp->arr[i]==0 && i>0)
	{
		temp->arr[i]=9;
		i--;
	}
	//border case like 1000 where the size of the array has to decrease by 1
	if(temp->arr[i]==1 && i==0)
	{
		//the extra space that has to be decremented can be used for null char, so temp->size only
		char *str=(char*)malloc((temp->size)*sizeof(char));
		int j;
		for(j=0;j<temp->size-1;j++)
		{
			str[j]='9';
		}
		str[j]='\0';
		ti=intal_create(str);
		intal_destroy(temp_intal);//destroy intal only when the size changes
		return ti;
	}
	if(temp->arr[i]!=0)
		(temp->arr[i])-=1;
	return temp;
}

void* intal_add(void* intal1, void* intal2)
{
	int diff,n,i;
	void *intal,*temp_intal;int flag=0;
	inlat temp1,temp2,temp3;
	temp1 = (inlat)intal1;
	temp2 = (inlat)intal2;

	if(temp1->size > temp2->size)
	{
		n=temp1->size;
		flag=1;
		diff=temp1->size - temp2->size;
		temp_intal=intal_create(intal2str(intal2));
		temp_intal=add_pre_zeroes(temp_intal,diff);
		temp3 = (struct intarblen*)temp_intal;
	}
	else if(temp2->size >= temp1->size)
	{
		n=temp2->size;
		flag=2;
		diff=temp2->size - temp1->size;
		temp_intal=intal_create(intal2str(intal1));
		temp_intal=add_pre_zeroes(temp_intal,diff);
		temp3 = (struct intarblen*)temp_intal;
	}

	inlat temp=(inlat)malloc(sizeof(struct intarblen));
	temp->arr=(short int*)malloc((n+1)*sizeof(short int));
	temp->size=n+1;

	int dig,r=0,q=0;
	for(i=n-1;i>=0;i--)
	{
		if(flag==2)
		{
			dig=temp2->arr[i]+temp3->arr[i]+q;
			r=dig%10;
			q=dig/10;
			temp->arr[i+1]=r;
		}
		else if(flag==1)
		{
			dig=temp1->arr[i]+temp3->arr[i]+q;
			r=dig%10;
			q=dig/10;
			temp->arr[i+1]=r;
		}
	}	
	temp->arr[0]=q;
	//intal_destroy(temp_intal);
	remove_pre_zeroes(&temp);
	return temp;
}

void* intal_diff(void* intal1, void* intal2)
{
	int diff,n;
	void *intal,*temp_intal;int flag=0;
	inlat temp1,temp2,temp3;
	temp1 = (inlat)intal1;
	temp2 = (inlat)intal2;
	remove_pre_zeroes(&temp1);
	remove_pre_zeroes(&temp2);
	if(temp1->size > temp2->size)
	{
		n=temp1->size;
		flag=1;
		diff=temp1->size - temp2->size;
		temp_intal=intal_create(intal2str(intal2));
		temp_intal=add_pre_zeroes(temp_intal,diff);
		temp3 = (struct intarblen*)temp_intal;
	}
	else if(temp2->size >= temp1->size)
	{
		n=temp2->size;
		flag=2;
		diff=temp2->size - temp1->size;
		temp_intal=intal_create(intal2str(intal1));
		temp_intal=add_pre_zeroes(temp_intal,diff);
		temp3 = (struct intarblen*)temp_intal;
	}

	inlat temp=(inlat)malloc(sizeof(struct intarblen));
	temp->arr=(short int*)malloc((n)*sizeof(short int));
	temp->size=n;
	int carry=0,sub,j,i;
	if(flag==1)
	{
		for(j=0;j<n;j++)
		{
			if(temp1->arr[j]>temp3->arr[j])
			{
				/*intal1 - intal2*/
			    for(i=n-1;i>=0;i--)
			    {
			        sub = (temp1->arr[i])-(temp3->arr[i])-carry;
			        if (sub < 0)
			        {
			            sub+=10;
			            carry = 1;
			        }
			        else
			            carry = 0;
			        temp->arr[i]=sub;
			    }
				break;
			}
			else if(temp3->arr[j]>=temp1->arr[j])
			{
				/*intal2 - intal1*/
			    for(i=n-1;i>=0;i--)
			    {
			        sub = (temp3->arr[i])-(temp1->arr[i])-carry;
			        if (sub < 0)
			        {
			            sub+=10;
			            carry = 1;
			        }
			        else
			            carry = 0;
			        temp->arr[i]=sub;
			    }
				break;
			}
		}
	}
	else if(flag==2)
	{
		for(j=0;j<n;j++)
		{
			if(temp2->arr[j]>temp3->arr[j])
			{
				/*intal1 - intal2*/
			    for(i=n-1;i>=0;i--)
			    {
			        sub = (temp2->arr[i])-(temp3->arr[i])-carry;
			        if (sub < 0)
			        {
			            sub+=10;
			            carry = 1;
			        }
			        else
			            carry = 0;
			        temp->arr[i]=sub;
			    }
				break;
			}
			else if(temp3->arr[j]>=temp2->arr[j])
			{
				/*intal2 - intal1*/
			    for(i=n-1;i>=0;i--)
			    {
			        sub = (temp3->arr[i])-(temp2->arr[i])-carry;
			        if (sub < 0)
			        {
			            sub+=10;
			            carry = 1;
			        }
			        else
			            carry = 0;
			        temp->arr[i]=sub;
			    }
				break;
			}
		}
	}
	//intal_destroy(temp_intal);
	remove_pre_zeroes(&temp);
	return temp;
}

int intal_compare(void* intal1,void* intal2)
{
	inlat temp1=(inlat)intal1;
	inlat temp2=(inlat)intal2;
	remove_pre_zeroes(&temp1);
	remove_pre_zeroes(&temp2);
	if(temp1->size>temp2->size) return 1;
	if(temp2->size>temp1->size) return -1;
	for(int i=0;i<temp1->size;i++)
	{
		if(temp1->arr[i]>temp2->arr[i])
			return 1;
		if(temp2->arr[i]>temp1->arr[i])
			return -1;
	}
	return 0;
}

void* intal_divide(void* intal1, void* intal2)
{
  inlat temp1,temp2,result,dividend,tempcpy;
  temp1=(inlat)intal1;
  temp2=(inlat)intal2;
   if(temp1 == NULL || temp2 == NULL) return NULL;

  tempcpy = (inlat)malloc(sizeof(struct intarblen));
  tempcpy->arr = (short int*)malloc(temp1->size*sizeof(short int));
  tempcpy->arr = temp1->arr;
  tempcpy->size = temp1->size;

  remove_pre_zeroes(&temp1);
  remove_pre_zeroes(&temp2);
  
  if(temp1->size==0) return temp1;
  if(temp2->size==1 && temp2->arr[0]==0) return NULL;
  
  int h = intal_compare(temp1,temp2);
  if(h==0)
  {
    inlat e=(inlat)malloc(sizeof(struct intarblen));
    e->arr=(short int*)malloc(sizeof(short int));
    e->arr[0]=1;
    e->size=1;
    return e;
  }
  else if(h==-1)
  {
    inlat z=(inlat)malloc(sizeof(struct intarblen));
    z->arr=(short int*)malloc(sizeof(short int));
    z->arr[0]=0;
    z->size=1;
    return z;
  }

  if(temp2->size == 1 && temp2->arr[0] == 1)
    return temp1;

  result = (inlat)malloc(sizeof(struct intarblen));
  result->arr = (short int*)malloc(temp1->size*sizeof(short int)+1);
  result->arr[0] = 0;
  result->size = 0;

  if(temp1->size==temp2->size || ((temp1->size - temp2->size)==1))
  {
    while(h==0||h==1)
    {
      temp1=intal_diff(temp1,temp2);
      h=intal_compare(temp1,temp2);
      result->arr[0]++;
    }
    if(result->arr[0]<10)
    {
      result->size=1;
      return result;
    }
    else
    {
      result->size=2;
    }
    int q=result->arr[0];
    for(int i=1;i>=0;i--) 
    {
      result->arr[i] = q%10;
      q=q/10;
    }
    return result;
  }

  dividend=(inlat)malloc(sizeof(struct intarblen));
  dividend->arr=(short int*)malloc(temp1->size*sizeof(short int)+1);
  dividend->size=0;
  for (int i=0;i<temp2->size;i++) 
  {
    dividend->arr[i]=temp1->arr[i];
    dividend->size++;
  }
  h=intal_compare(dividend,temp2);
  if(h<0)
  {
    dividend->arr[dividend->size] = temp1->arr[dividend->size];
    dividend->size++;
    h=1;
  }
  tempcpy->arr=tempcpy->arr+dividend->size-1;
  tempcpy->size=tempcpy->size-(dividend->size-1);
  int count=0,q;
  while(tempcpy->size!=0)
  {
      q=0;
      while(h==0||h==1)
      {
        dividend=intal_diff(dividend,temp2);
        h=intal_compare(dividend,temp2);
        q++;
      }
      tempcpy->arr++;
      tempcpy->size--;
      result->arr[count++]=q;
      result->size++;
      dividend->arr[dividend->size++]=tempcpy->arr[0];
      h=intal_compare(dividend,temp2);
  }
  return result;
}

void* intal_multiply(void* intal1, void* intal2)
{
	inlat temp1,temp2,t1,t2;

	t1=(inlat)intal1;
	t2=(inlat)intal2;

	if(t1==NULL||t2==NULL) return NULL;

	temp1 = (inlat)malloc(sizeof(struct intarblen));
	temp1->arr=(short int*)malloc(sizeof(short int)*t1->size);
	temp1->size=t1->size;
	for(int i=0;i<t1->size;i++)
		temp1->arr[i]=t1->arr[i];
	
	temp2 = (inlat)malloc(sizeof(struct intarblen));
	temp2->arr=(short int*)malloc(sizeof(short int)*t2->size);
	temp2->size=t2->size;
	for(int i=0;i<t2->size;i++)
		temp2->arr[i]=t2->arr[i];

	remove_pre_zeroes(&temp1);
	remove_pre_zeroes(&temp2);
	inlat temp=KA(temp1,temp2);
	//intal_destroy(temp1);
	//intal_destroy(temp2);
	return temp;
}

inlat KA(void *intal1,void *intal2)
{
	void *temp_intal1,*temp_intal2;int n;
	inlat temp1=(inlat)intal1;
	inlat temp2=(inlat)intal2;
	inlat a,b,a1,a2,b1,b2;
	a=temp1;
	b=temp2;int i;int flag=0;
	if(a->size==b->size) n=a->size;
	else
	{
		if(a->size>b->size)
		{
			temp_intal1=add_pre_zeroes(temp2,(a->size-b->size));
			//intal_destroy(temp2);
			b=(inlat)temp_intal1;
			//a=temp1;
			n=temp1->size;
			flag=1;
		}
		else
		{
			temp_intal1=add_pre_zeroes(temp1,(b->size-a->size));
			a=(inlat)temp_intal1;
			//b=temp2;
			n=temp2->size;
			flag=2;
		}
	}
	if(n==1)
	{
		struct intarblen *prod;
        prod=(inlat)malloc(sizeof(struct intarblen));
        prod->arr=(short int*)malloc(2*sizeof(short int));
        prod->size=2;
        int k=temp1->arr[0]*temp2->arr[0];
		prod->arr[1]=k%10;
		k/=10;
		prod->arr[0]=k;
		//remove_pre_zeroes(&prod);
		return prod;
	}
	
	if(n%2!=0)
	{
		temp_intal1=add_pre_zeroes(a,1);
		temp_intal2=add_pre_zeroes(b,1);
		a=(inlat)temp_intal1;
		b=(inlat)temp_intal2;
		n=a->size;
	}

	a1=(inlat)malloc(sizeof(struct intarblen));
	a1->arr=(short int*)malloc((n/2)*sizeof(short int));
	a1->size=(n/2);

	a2=(inlat)malloc(sizeof(struct intarblen));
	a2->arr=(short int*)malloc((n/2)*sizeof(short int));
	a2->size=(n/2);

	b1=(inlat)malloc(sizeof(struct intarblen));
	b1->arr=(short int*)malloc((n/2)*sizeof(short int));
	b1->size=(n/2);

	b2=(inlat)malloc(sizeof(struct intarblen));
	b2->arr=(short int*)malloc((n/2)*sizeof(short int));
	b2->size=(n/2);
	//now n is even
	//split a and b to a1 and a2

	for(i=0;i<(n/2);i++)
		a1->arr[i]=a->arr[i];
	int j=0;
	for(i=(n/2);i<(n);i++)
	{
		a2->arr[j]=a->arr[i];
		j++;
	}
	for(i=0;i<(n/2);i++)
		b1->arr[i]=b->arr[i];

	j=0;
	for(i=(n/2);i<(n);i++)
	{
		b2->arr[j]=b->arr[i];
		j++;
	}
	//void *p1,*p2,*p3,*mp;
	inlat p1,p2,p3,mp;
	p1=(inlat)KA(a1,b1);
	p2=(inlat)KA(a2,b2);
	void *x,*y;
	x=intal_add(a1,a2);
	y=intal_add(b1,b2);
	p3=KA(x,y);
	//printf("%d-%s\n",n,intal2str(intal_diff(p3,p2)));
    mp=intal_diff(intal_diff(p3,p2),p1);

    //p1*10^n
    remove_pre_zeroes(&p1);
    remove_pre_zeroes(&p2);
    remove_pre_zeroes(&p3);
    
    void *t1,*t2;
	char *str_p1;
	str_p1=(char*)malloc((p1->size+n+1)*sizeof(char));
	for(i=0;i<p1->size;i++)
		str_p1[i]=p1->arr[i]+'0';
	for(i=p1->size;i<(p1->size)+n;i++)
	{
		str_p1[i]='0';
	}
	str_p1[i]='\0';
	t1=intal_create(str_p1);

	char *str_mp;int k=n/2;
	str_mp=(char*)malloc(((mp->size)+k+1)*sizeof(char));
	for(i=0;i<mp->size;i++)
		str_mp[i]=mp->arr[i]+'0';
	for(i=mp->size;i<mp->size+k;i++)
	{
		str_mp[i]='0';
	}
	str_mp[i]='\0';
	t2=intal_create(str_mp);

    void *t3,*t;
    inlat blah;
    t3=intal_add(t1,t2);
    t=intal_add(t3,p2);
    blah=(inlat)t;
    remove_pre_zeroes(&blah);
	return blah;
}

void* intal_pow(void* intal1, void* intal2)
{
	if(intal1==NULL||intal2==NULL) return NULL;
	int n;
	char *str1,*str2,*u;
	char *n1=intal_create("1");
	char *n2=intal_create("2");
	inlat temp1=(inlat)intal1;
	inlat temp2=(inlat)intal2;
	remove_pre_zeroes(&temp1);
	remove_pre_zeroes(&temp2);
	str1=intal2str(temp1);
	str2=intal2str(temp2);
	int check=str2[strlen(str2)-1]-'0';
	if(strcmp(str2,"0")==0)
		return n1;
	inlat temp_intal=intal_pow(temp1,intal_divide(temp2,n2));
	if(check%2==0)
		return intal_multiply(temp_intal,temp_intal);
	else
	{
		void *p1,*p2;
		p2=intal_multiply(temp_intal,temp_intal);
		p1=intal_multiply(temp1,p2);
		return p1;
	}
}