#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, j, w, col,*dis,d,abs_flag,c,e,fc,dc,bytes;
        string dir,dir1,*filter;
        mixed *file,*arrge;
        seteuid(geteuid(this_player(1)));
        abs_flag=0;
        dir = resolve_path(me->query("cwd"), arg);
        arg=dir;

        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )
                dir += "/";

        file = get_dir(dir, -1);
        if( !sizeof(file) ) {
                if (file_size(dir) == -2) 
                        return notify_fail("Ŀ¼�ǿյġ�\n");
                else
                        return notify_fail("û�����Ŀ¼��\n");
        }
        //����arg�е�'*','?'
        filter=explode(arg,"/");
        j=sizeof(filter);
        if(j>0)
        {
                arg=(strsrch(filter[0],"*")==-1&&strsrch(filter[0],"?")==-1)?filter[0]:"";
                for(i=1;i<j;i++) {
                        if(strsrch(filter[i],"*")!=-1)
                                i++;
                        else
                                if(strsrch(filter[i],"?")!=-1)
                                        i++;
                                else
                                        arg+="/"+filter[i];
                }
        }
        i = sizeof(file);
	c = 0;
	w = 0;
        dis=allocate(i);
        while(i--) {
                dir1=file[i][0];
                dir1=(arg[strlen(arg)-1]=='/')?(arg+dir1):(arg+"/"+dir1);
                dir1=(dir1[0]=='/')?dir1:"/"+dir1;
                if(file[i][0]=="."||file[i][0]=="..")
                        continue;//ֱ���������ˣ���Ȼ".."���ǲ���������ʾ
                if(file_size(dir1)==-1)
                        dis[d++]=i+1;
                if(file[i][1]==-2) {
                	file[i][0] =file[i][0]+"/";
                        c++;
		}
                if (strlen(file[i][0])>w) 
                        w = strlen(file[i][0]) + 1;
        }
	fc = sizeof(file) - c;
	dc = c;
        write("\nĿ¼��" + dir + "\n");
        col = 70 / (w+6);
	e = 0;
        d = 0;
        bytes = 0;
        j = sizeof(file);
        arrge = allocate(j);
        if (sizeof(file)) {
                for(i=0; i<j; i++) {
                        d++;
                        if(member_array(i+1,dis)==-1) {//�ж�Ŀ¼�Ƿ�ɶ�i+1
				if(file_size(dir + file[i][0])==-2) {
					arrge[e] = allocate(3);
					arrge[e][0] = file[i][0];
					arrge[e][1] = file[i][1];
					arrge[e][2] = file[i][2];
					e++;
				}
				else {
					bytes += file[i][1];
					arrge[c]=allocate(3);
					arrge[c][0] = file[i][0];
					arrge[c][1] = file[i][1];
					arrge[c][2] = file[i][2];
					c++;
				}
			}
                        else {
				dis[member_array(i+1,dis)]=e+1;
				d--;
				arrge[e] = allocate(3);
				arrge[e][0] = file[i][0];
				arrge[e][1] = file[i][1];
				arrge[e][2] = file[i][2];
				e++;
                        }
                }
                d = 0;
                for(i=0; i<j; i++) {
                        d++;
                        if(member_array(i+1,dis)==-1)//�ж�Ŀ¼�Ƿ�ɶ�i+1
                                printf("%4d %-*s%s", arrge[i][1]/1024 + 1, w+1,
                                        arrge[i][0] + (find_object(dir + arrge[i][0])? "*":" ") ,
                                        (i+1==j)?"\n":(((i+1)%col)?"  ":"\n"));
                        else {
				d--;
				printf(HIY"%4d %-*s%s"NOR, arrge[i][1]/1024 + 1, w+1,
					arrge[i][0] + (find_object(dir + arrge[i][0])? "*":" ") ,
					(i+1==j)?"\n":(((i+1)%col)?"  ":"\n"));
			}
		}
		printf("\n                          %4d file(s)       %d bytes", fc, bytes);
		printf("\n                          %4d dir(s)", dc);
	}
        else write("    û���κε�����\n");
        write("\n");
        
        return 1;       
}

int help(object me)
{
        write(@HELP
ָ���ʽ: ls [<·����>]
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
��ɫĿ¼Ϊ��Ȩ�޶�ȡ��Ŀ¼�� 
HELP
        );
        return 1;
}