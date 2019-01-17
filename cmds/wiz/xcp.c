// xcp.c 
// Ϊ�˱���ݹ�̫��벻Ҫ���ý��뼶�𳬹�16��.

inherit F_CLEAN_UP;
int help();
int do_cp(string,string,string,int);
string resolvePath(string,int);
int main(object me, string arg)
{
        string  path,wild,dest;
        int level;
        level=15;
        seteuid(geteuid(me));

    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,dest)!=2)
    {
        if(sscanf(arg,"-d%d %s %s",level,path,dest)!=3)
                if(sscanf(arg,"%s %s",path,dest)!=2)
                {
                        write ("\n������������\n\n");
                        return help();
                }
    }
    else
        level=15;//��-d����Ĭ�ϼ���Ϊ���м�
    if(level<0) level=1;
    if(level>15) level=15;
    dest=resolve_path(me->query("cwd"),dest);
    //����path�ֽ��wild
    path=resolve_path(me->query("cwd"),path);
    write("δ����·����\t"+path+"\n");
    //write("�����Ƶ�Ŀ��·����\t"+dest+"\n");
    write("����Ŀ¼����\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("������·����\t"+path+"\n");
    write("������ͨ�����\t"+wild+"\n");
    write("������Ŀ��·����\t"+dest+"\n\n");
    do_cp(path,wild,dest,level);
    write("\n���ƽ�����\n");
    return 1;
}

string resolvePath(string path,int op)
{
        string *dn,tmp;
        int i;
        if(path=="/")//�����������⴦��
                return (op)?"/":"*";
        dn=explode(path,"/");
        if(op)//opΪ��0��ʾ��Ҫ����·��
        {
                //dn=dn-({dn[sizeof(dn)-1]});
                //tmp=implode(dn,"/")+"/";
                //����ĳ��򲻺ã����ܶ�ͬ��·����ȷ���������粻����/log/log�ļ�������
                tmp="/";
                for(i=0;i<sizeof(dn)-1;i++)
                {
                        //write("�ϲ�"+dn[i]+"\n");
                        tmp+=dn[i]+"/";
                }
                return tmp;
        }
        else
                return dn[sizeof(dn)-1];
}
int do_cp(string path,string wild,string dest,int level)
{
        //int i;string *fs;
        string file;
        reset_eval_cost();//��������ʣ��ִ��ʱ�䣬�������ã�
        if(dest[sizeof(dest)-1]!='/')//���ز����٣���Ȼ�Ͳ�����ȷ����Ŀ��·��
        dest=dest+"/";
        if(this_player()->query("env/debug"))
                write("��ʼ����"+path+wild+"��"+dest+"\n");
        if(level<0)
        {
                //write("�������ƣ������ٽ��롣\n");
                return 0;
        }
        
        foreach(file in get_dir(path+wild))
        {

                if(file=="."||file=="..")
                        continue;
                
                switch(file_size(path+file))
                {
                        case -1:
                                //�޷���ȡ��Ŀ¼������
                                break;
                        case -2:
                                if(file!="."&&file!="..")
                                        do_cp(path+file+"/","*",dest+file+"/",level-1);
                                break;
                        default:
                                assure_file(dest+file);
                                //write("�����ļ���"+path+file+"��"+dest+file+"\n");
                                cp(path+file,dest+file);
                }
                
        }
        return 1;
}

int help()
{
  write(@HELP

ָ���ʽ : xcp [-d[0-15]] Դ·�����ļ� Ŀ��·��
��ָ��������ָ����Ŀ¼���ļ����Ƶ�ָ����Ŀ¼ȥ��
֧��ͨ���������ָ������һ����Ŀ¼��ȡ�
HELP
    );
    return 1;
}

