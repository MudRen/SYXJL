#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
        int n,k,x,y,cc,pc,g=1;

        write("Move Mountain Game \nGame Begin\n");
        pc=cc=0;
        for( ; ; )
        {
                write("                         No.%2d game \n",g++);
                write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                write("How many mountain are there?");
                //scanf("%d", &n);
                if(!n)
                        break;
                do {
                        write("How many mountain are allowed to each time?");
                        //scanf("%d",&k);
                        if (k>n||k<1)
                                write("Repeat again !\n");
                } while (k>n||k<1);
                do {
                        write("How many mountains do you wish to move away?");
                        //scanf("%d",&x);
                        if (x<1 || x>k || x>n)
                        {
                                write("Illegal, again please!\n");
                                continue;
                        }
                        n-=x;
                        write("There are %d mountains left now.\n",n);
                        if (!n)
                        { 
                                write("-----------I win,You are failure.------------\n\n");
                                cc++;
                        }
                        else
                        {
                                y=(n-1)%(k+1);
                                if(!y) y=1;
                                n-=y;
                                write(" Computer move %d mountains away.\n",y);
                                if (n) write("There are %d mountains left now.\n",n);
                                else
                                {
                                        write("-----------I am failure,You win.------------\n\n");
                                        pc++;
                                }
                        }
                } while(n);
        }
        write("Games in total have been played %d.\n",cc+pc);
        write("Your score is win %d ,lose %d.\n",pc,cc);
        write("My score is win %d ,lose %d.\n",cc,pc);

        return 1;
}

