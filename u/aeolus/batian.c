// Overlord Sword ����������

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(WHT"����������"NOR,({ "overlord sword", "overlord", "sword"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "steel");
                set("long", WHT"����һ��������ӡ�ľ����񽣡���������,ѩ�׵Ľ�������Ƕһ��ɢ����ͽ����޼۱�
�顣\n����ɫ�Ľ���ɢ����һ˿˿�Ʒ���ʹ�İ�����\n"NOR);
        }
        init_sword(1);
        setup();
}

int init()
{
	add_action("do_wield","wield");
	add_action("do_unwield","unwield");
}

int do_wield(string arg)
{
	object me;
	me=this_player();

	if(!arg&& arg!="sword") return notify_fail(HIR"��Ҫ���ʲô��\n"NOR);
	if(me->query("id")!="aeolus"){
		message_vision(HIR"��û�н���񽣵�������\n"NOR, me);
		return 1;
	}
	set("wield_msg",HIY"$N���ֽ��հ����������Ľ���������ʳ���ж�ָ�������棬�������������������ͻȻ��$N��
߳һ�������ţ�����\nɲʱ�䣬�����������Ӱ���ɫ����˴�Ŀ�Ľ��ɫ�������Ϊ֮һ����ʹ����Ҳ�����Ȼʧɫ��\n"NOR);
	set_name(HIY"����������"NOR,({ "overlord sword", "overlord", "sword"}) );
	set("long", HIY"�����׽��ľ����񽣡���������,ѩ�׵Ľ�������Ƕһ��ɢ����ͽ����޼۱��顣\n����ɫ�Ľ�
��ɢ����һ˿˿�Ʒ���ʹ�İ�����\n"NOR);
        init_sword(9999);
        set("value", 10000000);
}

int do_unwield(string arg)
{
	object me;
	me=this_player();

	if(!arg && arg!="sword") return notify_fail(HIR"��Ҫ��ӡʲô��\n"NOR);
	if(me->query("id")!="aeolus"){
		message_vision(HIR"��û�н���񽣵�������\n"NOR, me);
		return 1;
	}
        set_name(HIB"����������"NOR,({ "overlord sword", "overlord", "sword"}) );
        set("unwield_msg",HIB"$N˫�����հ������������߾ٹ�ͷ���ѽ��еİ������������ع鵤��̶���$N�����񽣺�
��һ�������գ�����\n���ͬʱ��������������Ŀ���ɫ��â�����ذ���������ȡ����֮�������ֽ����һƬ������\n"NOR);
        init_sword(1);
        set("value", 1);
}
