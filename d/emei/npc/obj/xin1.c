// ������--��ü����������
// -- BY bibi--
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("������", ({"jieshao-xin1", "xin1", "xin"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","��ü����ͬʦ���Ȼ���ʤ�˵�ƾ֤��\n");
                set("material", "paper");
                set("no_give_user", 1);
        }
}
