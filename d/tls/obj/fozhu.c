// fozhu.c

inherit ITEM;

void create()
{
	set_name("����", ({"fozhu"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"���Ǵ�����ͨͨ�ķ��飬ϸϸ�ۿ��ſ��������С����١�����С�֡��\n");
	set("unit", "��");
	set("weight", 10);
        set("no_drop", "�������������뿪�㡣\n");
        set("material", "wood");
	set("tianlongsi",1);
}
}

