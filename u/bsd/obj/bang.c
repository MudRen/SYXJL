//bang.c ��
//by bsd 13/12/2000

#include <ansi.h>
inherit ITEM;

int do_read(string arg);
void create()
{
      

  set_name(HIY "��"HIR"��"HIY"��"HIR"��"HIY"��"HIR"��"HIY"��" NOR, ({ "guangrong bang","bang" }) );
        
        set("unit", "��");
        set("long", "����һ��������¼������������Ĺ��ٰ�
������꣬�������ţ�������ɡ����ϵ�
����ȴ����һ����һ����ֻ������д�ţ�
                    
            "HIW"�ú�ѧϰ ��������"NOR"

             һ��"CYN"����ʮ��"YEL"����"NOR"
             ����"CYN"ʮ��"HIR"ɱ�˿�ħ"NOR"
             ����"CYN"ʮ��"HIC"���ָ���"NOR"
             �ģ�"CYN"����ʮ��"RED"����"NOR"
             �壺"CYN"ʮ��"HIR"��ȭ�޵�"NOR"
             ��: "CYN"ʮ��"HIM"��ѧ����"NOR"
             �ߣ�"CYN"����ʮ��"GRN"����"NOR"
             �ˣ�"CYN"ʮ��"BLU"�Ṧ����"NOR"

�������(read ���)���������ء�\n");
        
        set("material","steel");
        set_weight(10000000);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
       string str;
	if(!arg||arg=="") 
	   return notify_fail("��Ҫ�Ķ���һ�����У�\n");
switch(arg)
	{
		case "һ": arg ="rich";			break;
		case "��": arg = "pker";		break;
		case "��": arg = "exp";			break;
		case "��": arg = "sword";		break;
		case "��": arg = "unarmed";		break;
		case "��": arg = "literate";	break;
		case "��": arg = "blade";		break;
		case "��": arg = "dodge";		break;
		default : arg = "none";			break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}
