// jinshe-jian ���߽�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("���佣",({ "zhenwu jian", "zhenwu", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 600000);
                set("material", "steel");
                set("long", "����һ���ĳ���������������ı�������ϻ��������Ž�˿��
�����ֱ�����������񲻿ɵ�������͸����һ��������\n");
                set("wield_msg", HIY "$Nһ�Ľ�ϻ��������һ��$n�������������������
��â���¡� ....$N���ɵô��ĵ�����һ��ɱ����\n" NOR);
                set("unwield_msg", HIY "���佣����һ����⣬��ৡ��ط��뽣�ʡ�\n" NOR);
                set("unequip_msg", HIY "���佣����һ����⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
        init_sword(600);
        setup();
}
