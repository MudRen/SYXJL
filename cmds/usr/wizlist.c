// wizlist.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *list;

        write("��"HIW + MUD_NAME + NOR"��" + "Ŀǰ����ʦ�У�\n");
        write("��������������������������������������������������������\n");
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIW"������ܹܡ� ��"NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==7) ? "("HIW+list[i]+NOR") " : "");
        write("\n"HIR"���˲����� ��"NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==6) ? "("HIR+list[i]+NOR") " : "");
	write("\n"HIM"���������� ��"NOR);
        for(int j=0; j<sizeof(list); j++)
                printf("%s", (wiz_level(list[j])==5) ? "("HIM+list[j]+NOR") " : "");
        write("\n"HIY"����ͥ������ ��"NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==4) ? "("HIY+list[i]+NOR") " : "");
        write("\n"HIG"����ң���ɡ� ��"NOR);
        for(int k=0; k<sizeof(list); k++)
                printf("%s", (wiz_level(list[k])==3) ? "("HIG+list[k]+NOR") " : "");
        write("\n"HIC"����ͯ��Ů�� ��"NOR);
        for(int l=0; l<sizeof(list); l++)
                printf("%s", (wiz_level(list[l])==2) ? "("HIC+list[l]+NOR") " : "");
       
        write("\n��������������������������������������������������������\n");
        write("�ϼƹ��У� "HIR + sizeof(list) + NOR" λ��ʦ�����С�\n");
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}




