#include <ansi.h>

inherit F_CLEAN_UP;

int main()
{    
        object me = this_player();
        string str,pai,pai2;
	int mp_num,i,degree;
        if( !pai = me->query("family/family_name"))
		return notify_fail("�㻹û�м����κ����ɣ�\n"); 
        write("���ʦ��"+me->query("family/family_name")+"�ͱ�����ɼ�Ĺ�ϵ�̶ȣ�\n");
        str = read_file("/hate/mp_num",1,1);
        sscanf(str,"%d",mp_num);
        for(i=0;i<mp_num-1;i++)
        {
		str = "";
		str = read_file("/hate/"+pai,i+1,1);
		sscanf(str,"%s %d",pai2,degree);
		str = " ";
		if(degree >=0 )
			str += sprintf("%s%7d"+NOR, HIW+pai2+HIG, degree);
		else str += sprintf("%s%7d"+NOR, HIW+pai2+HIR, degree);
		if(i==2 || i==5 || i==8 || i==11 || i==14 || i==17 || i==20 || i==mp_num-2)str += "\n"NOR;
		else str += "      "NOR;
		write(str);
        }
        return 1;
}
