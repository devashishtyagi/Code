#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

//Fast IO Section
#define MAX_BUFFER (512*1024)
 
class FastIO
{
private:
    static char inBuffer[MAX_BUFFER];
    static char outBuffer[MAX_BUFFER];
    static int inBuffFilled,inBuffCurrent;
    static int outBuffFilled;
    static inline void fillInBuffer()
    {
        inBuffFilled = fread(inBuffer,1,MAX_BUFFER,stdin);
        inBuffCurrent = 0;
    }
    static inline char getNextChar()
    {
        if(inBuffCurrent>=inBuffFilled){fillInBuffer();}
        return inBuffer[inBuffCurrent++];
    }
    static inline void skipSpaces(){while(inBuffer[inBuffCurrent] == ' ' || inBuffer[inBuffCurrent] == '\n')inBuffCurrent++;}
public:	
    static unsigned long inReadNum()
    {
        long num = 0;
        skipSpaces();
        char ch;
        while(1)
        {
            ch = getNextChar();
            if(ch >= '0' && ch <= '9')
            {
                num = (num*10)+(ch-'0');
            }
            else
            {
                return num;
            }
        }
    }
    static void inReadString(char * output)
    {
        skipSpaces();
        char * pointer = output;
        char ch;
        int count = 0;
        while(1)
        {
            ch=getNextChar();
            if (ch >= '0' && ch <= '9')
            {
                //std::cout<<"I am here "<<ch<<" "<<count<<std::endl;
                *pointer = ch;
                pointer++;
                count++;
            }
            else
            {
                *pointer = '\0';
                break;
            }
        }
    }
            
    static inline void flushOutBuffer()
    {
        fwrite(outBuffer,1,outBuffFilled,stdout);
        outBuffFilled = 0;
    }
private:	
    static inline void outBufferCheck(){if(outBuffFilled >= (MAX_BUFFER-11))flushOutBuffer();}
    static unsigned long recursiveOutNum(unsigned long num)
    {
        if(num && num < 10){outBuffer[outBuffFilled++] = '0' + num;}
        else
        {
            recursiveOutNum(num/10);
            outBuffer[outBuffFilled++] = '0' + (num%10);
        }
    }
public:	
    static inline void outWriteSpace(){outBufferCheck();outBuffer[outBuffFilled++] = ' ';}
    static inline void outWriteNewLine(){outBufferCheck();outBuffer[outBuffFilled++] = '\n';}
    static inline void outWriteNum(unsigned long num)
    {
        outBufferCheck();
        if(num) recursiveOutNum(num);
        else outBuffer[outBuffFilled++] = '0';
    }
};
int FastIO::inBuffFilled=0,FastIO::inBuffCurrent=0,FastIO::outBuffFilled=0;
char FastIO::inBuffer[MAX_BUFFER],FastIO::outBuffer[MAX_BUFFER];
//End of Fast IO Section

int main(void){
    char sequence[10002];
    for(int i=0; i<201; i++){
        FastIO::inReadString(sequence);
        printf("%d\n",strlen(sequence));
    }
}
