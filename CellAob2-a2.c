/*SIZE=100:576繧ｹ繝・ャ繝励〒0縺ｫ遯∝ｦょ庶譚・SIZE=200:398繧ｹ繝・ャ繝励〒遯∝ｦ・縺ｫ蜿取據
蜴溷屏荳肴・
*///dd27
#include<stdio.h>
#include <math.h>
#include <memory.h>
#include <highgui.h>
#include <cv.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 500
#define EFFECT 0.4
#define SPITE 1000000
void effect(double *,double *,long int,unsigned int*);
int effect4(double *,double *,long int,unsigned int*);
void write4(char* ,char *);

enum { len = 12 };

int func(void) {
  char id[len];
  int r;
  int num;
  /* ... */
  struct timespec ts;
  if (clock_gettime( CLOCK_REALTIME,&ts) == 0) {
  }
 srandom(ts.tv_nsec ^ ts.tv_sec);  
r = random(); 
 num = snprintf(id, len, "ID%-d", r);  
return r;
}

int main(int argc, char *argv[] ){

unsigned char v;
 char v1[256];
 char v2[25];
 char v3[25];
 char v4[25];
unsigned int g[256];
unsigned int g1[31];
double *dat,*dat1,*adat,*adat1,b=0,c=0,d=0,fps=5.0;
long int a,e=0,m,m1;
char windowName2[] = "camera2";
cvNamedWindow( windowName2, CV_WINDOW_AUTOSIZE );
IplImage *input = cvCreateImage( cvSize(SIZE,SIZE), IPL_DEPTH_8U, 1);
dat=NULL;
dat=(double *)malloc(sizeof(double) * (SIZE*SIZE)*1);

dat1=NULL;
dat1=(double *)malloc(sizeof(double) * (SIZE*SIZE)*1);
if(dat==NULL){
printf("memory error");
exit(0);
}
if(dat1==NULL){
printf("memory error2");
exit(0);
}

	if(argc>=2){
		for(a=0;;a++){
			v2[(int)a]=argv[1][(int)a];
			v3[(int)a]=argv[1][(int)a];
			v4[(int)a]=argv[1][(int)a];
			if(argv[1][(int)a]=='\0')
			{
				m1=a;
			
				break;
			}
			
				}
	}
	if(argc>=3){
		for(a=0;;a++){

		g1[(int)a]=argv[2][(int)a]-'0';
		if(argv[2][(int)(a+1)]=='\0')
				{
					//m1=a;
			
					break;
				}
			



			}
		}
v2[m1]='.';
v2[m1+1]='t';
v2[m1+2]='x';
v2[m1+3]='t';
v2[m1+4]='\0';
v3[m1]='.';
v3[m1+1]='j';
v3[m1+2]='p';
v3[m1+3]='g';
v3[m1+4]='\0';
e=0;
v4[m1]='.';
v4[m1+1]='a';
v4[m1+2]='v';
v4[m1+3]='i';
v4[m1+4]='\0';
e=0;
CvVideoWriter* outm=cvCreateVideoWriter(v4,CV_FOURCC('M','J','P','G'),fps,cvSize(SIZE,SIZE),0);

for(a=0;a<SIZE*SIZE*1;a++)
	{
	if(e==0){
		m=func()%SPITE; 
			if(m==1)
				dat1[(int)a]=1;
			else 
				dat[(int)a]=0;
		dat[(int)a]=dat1[(int)a];
		}
	}
printf("type \n");
/*
for(a=0;a<256;a++)//effect
	{
		if(e==0)
			{
				g[(int)a]=(unsigned int)func()%3;
				printf(" %d ",g[(int)a]);
				v1[(int)a]=g[(int)a]+'0';
			}
	}
*/
for(a=0;a<32;a++)//effect4
	{
		if(e==0)
			{
				if(!(argc>=3))g1[(int)a]=(unsigned int)func()%2;
				printf(" %d ",g1[(int)a]);
				v1[(int)a]=g1[(int)a]+'0';
			}
	}
//v1[0]=1;
v1[32]='\0';
printf("\n");
if(argc>=2)
	write4(v2,v1);
e=1;
while( cvWaitKey( 1 ) != 'a')
	{
	adat=dat;
	adat1=dat1;
	d=0.;


	for(a=0;a<SIZE*SIZE*1;a++){
		//if(e==0){dat1[(int)a]=func()%2; dat[(int)a]=dat1[(int)a];}
		//else{
		//b=11.0;
		//c=fmod((double)func(),2);
		*adat=*adat1+c+b;
		//effect(dat,dat1,a,g);//symotainias縺ｧ縺ｯ縺ｪ縺・→縺薙ｍ謾ｹ蝟・	//if(dat[(int)a]<0)dat[(int)a]=-dat[(int)a];
		if(effect4(dat,dat1,a,g1)==1)
				d++;
		//printf("e%d %lf %lf\n",e,(*adat)*255,*adat1);
		input->imageData[(int)a]=(*adat)*254;
		//printf("e%d %lf %lf\n",e,*adat,*adat1);
		//d+=fmod(*adat,255.);
			//if(*adat!=*adat1)
					//d++;
		//if(a>240000)printf("%d %lf %lf %lf\n",e,*adat,*adat1,d);
		//}
		adat++;adat1++;
				}
	e++;
	printf("t=%ld d=%lf\n",e,d/(SIZE*SIZE));
	d=0.;
	adat=dat;
	adat1=dat1;
	for(a=0;a<SIZE*SIZE*1;a++)
		{
			*adat1=*adat;
			adat++;
			adat1++;
		}
	cvShowImage("camera2",input);
	cvWriteFrame(outm,input);
	//cvSaveImage(v3, input);//for server
	//printf("%d average=%lf\n",e,d/(double)(SIZE*SIZE));
	}
















	cvSaveImage(v3, input);
    cvReleaseImage(&input);
    cvReleaseVideoWriter(&outm);
    cvDestroyWindow( windowName2 );
    free(dat);
    free(dat1);
    return 0;

}
/*
void effect(double *dat ,double *dat1,int a){
int t=0;
//double b[5]={0,0,0,0,0};
//printf("9 a=%d\n",a);
if((a-SIZE)>0)if((int)dat1[(int)a]==(int)dat1[a-SIZE]){if(t==0){dat[(int)a]+=EFFECT;t++;};dat[a-SIZE]+=EFFECT;t++;}
if((a-1)>0)if((int)dat1[(int)a]==(int)dat1[a-1]){if(t==0){dat[(int)a]+=EFFECT;t++;}dat[a-1]+=EFFECT;}
if((a+1)<SIZE*SIZE-1)if((int)dat1[(int)a]==(int)dat1[a+1]){if(t==0){dat[(int)a]+=EFFECT;t++;}dat[a+1]+=EFFECT;}
if((a+SIZE)<SIZE*SIZE-1)if((int)dat1[(int)a]==(int)dat1[a+SIZE]){if(t==0){dat[(int)a]+=EFFECT;t++;};dat[a+SIZE]+=EFFECT;}
//b[4]=b[4]/4.;
//dat[(int)a]+=(dat1[(int)a]-b[4]);
}
*/
void effect(double *dat ,double *dat1,long int a,unsigned int *s){
double t=0;
double b[8]={0,0,0,0,0,0,0,0};
//printf("eee=%d\n",a);
if(a-SIZE-1>0&&a-SIZE-1<SIZE*SIZE)b[0]=dat1[a-SIZE-1] ;else b[0]=1;
//printf("eee=%d\n",a);
if(a-SIZE>0&&a-SIZE<SIZE*SIZE)b[1]=dat1[a-SIZE] ;else b[1]=1;//over only
if(a-SIZE+1>0&&a-SIZE+1<SIZE*SIZE)b[2]=dat1[a-SIZE+1] ;else b[2]=1;//l
if(a-1>0&&a-1<SIZE*SIZE)b[3]=dat1[a-1] ;else b[3]=1;
if(a+1>0&&a+1<SIZE*SIZE)b[4]=dat1[a+1] ;else b[4]=1;
if(a+SIZE-1>0&&a+SIZE-1<SIZE*SIZE)b[5]=dat1[a+SIZE-1] ;else b[5]=1;
if(a+SIZE>0&&a+SIZE<SIZE*SIZE)b[6]=dat1[a+SIZE] ;else b[6]=1;//over only
if(a+SIZE+1>0&&a+SIZE+1<SIZE*SIZE)b[7]=dat1[a+SIZE+1];else b[7]=1;
if((a+1)%SIZE==0){
	b[2]=1;
	b[4]=1;
	b[7]=1;
		}
if((a+1)%SIZE==1){
	b[0]=1;
	b[3]=1;
	b[5]=1;
		}
//need to think about boundarys,now it is helix
//(a+1)%SIZE!=0or(a+1)%SIZE!=SIZE-1 may work
//a%SIZE==0 right a%SIZE==1 left?
t=b[0]*1+b[1]*2+b[2]*4+b[3]*8+b[4]*16+b[5]*32+b[6]*64+b[7]*128;
if(s[(int)t]==0)dat[(int)a]=0.;
if(s[(int)t]==1)dat[(int)a]=dat1[(int)a];
if(s[(int)t]==2)dat[(int)a]=1.;
//printf("eee=%d\n",a);
}
int effect4(double *dat ,double *dat1,long int a,unsigned int *s){
double t=0;
int r=0;
double b[5]={0,0,0,0,0};
//printf("eee=%d\n",a);
//if(a-SIZE-1>0&&a-SIZE-1<SIZE*SIZE)b[0]=dat1[a-SIZE-1] ;else b[0]=1;
//printf("eee=%d\n",a);
if(a-SIZE>0&&a-SIZE<SIZE*SIZE)b[0]=dat1[a-SIZE] ;else b[0]=1;//over only
//if(a-SIZE+1>0&&a-SIZE+1<SIZE*SIZE)b[2]=dat1[a-SIZE+1] ;else b[2]=1;//l

if(a-1>0&&a-1<SIZE*SIZE)b[1]=dat1[a-1] ;else b[1]=1;
b[2]=dat1[a];
if(a+1>0&&a+1<SIZE*SIZE)b[3]=dat1[a+1] ;else b[3]=1;
//if(a+SIZE-1>0&&a+SIZE-1<SIZE*SIZE)b[5]=dat1[a+SIZE-1] ;else b[5]=1;
if(a+SIZE>0&&a+SIZE<SIZE*SIZE)b[4]=dat1[a+SIZE] ;else b[4]=1;//over only
//if(a+SIZE+1>0&&a+SIZE+1<SIZE*SIZE)b[7]=dat1[a+SIZE+1];else b[7]=1;
if((a+1)%SIZE==0){
	//b[2]=1;
	/*b[4]=1;*/b[3]=1;
	//b[7]=1;
		}
if((a+1)%SIZE==1){
	//b[0]=1;
	/*b[3]=1;*/b[1]=1;
	//b[5]=1;
		}
//need to think about boundarys,now it is helix
//(a+1)%SIZE!=0or(a+1)%SIZE!=SIZE-1 may work
//a%SIZE==0 right a%SIZE==1 left?
t=b[0]*1+b[1]*2+b[2]*4+b[3]*8+b[4]*16;//+b[5]*32+b[6]*64+b[7]*128;
if(s[(int)t]==0)
{
	r=1;
	//printf("8888888888888\n");
	if(dat1[(int)a]==0)
		dat[(int)a]=1;
	else
		dat[(int)a]=0;
}
if(s[(int)t]==1)
	dat[(int)a]=dat1[(int)a];
//if(s[(int)t]==2)dat[(int)a]=1.;
//printf("eee=%d\n",a);
return r;
}
void write4(char* a,char *c){
	FILE *fp;
	char b[23];
	if ((fp = fopen(a, "a")) == NULL) {
	printf("file open error!!\n");
	exit;
}
if(fprintf(fp,"%s\n",c)<0)
	printf("file write error2");
fclose(fp);
}
	
	
	
	
	
	
	

