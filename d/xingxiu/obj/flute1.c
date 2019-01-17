// flute1.c

// by QingP



#include <ansi.h>

#include <weapon.h>



inherit SWORD;



int do_play(string arg);



void init()

{

	add_action("do_play", "play");

}



void create()

{

	set_name("���", ({"yu di", "di"}));

	set("unit", "֧");

	set_weight(170);

	set("long", "����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���ף���Ө�ɰ���\n"

	"���̲�ס������(play)����\n");

	set("value", 70000);

	set("material", "bamboo");

	set("wield_msg", "$N����һ�ӣ������Ѷ���һ֧��Ө�������ѡ�\n");

	set("unwield_msg", "$N��������һת��գ�ۼ������Ȼ����Ӱ�١�\n");



//	setup();

}



int do_play(string arg)

{

	if (!id(arg))

		return notify_fail("��Ҫ����ʲô��\n");

	message_vision( HIG "$N����ѷŵ��ڱߣ�����һ����һ�ɼ����������ԶԶ���˳�ȥ��\n"

		+ "�����������ＤԽ�������������з���������ȴʮ��������ȫ���ֵ���\n"

		+ "$N�ѵ��Ӵ��ø�һ�󣬵�һ����ɱ���ƹ�ޣ������ޱȡ�\n"NOR, this_player() );



	return 1;

}