inherit ROOM;

void create()
{
        set("short", "���Ϸ�ɽ��");
        set("long", @LONG
�������Ϸ��ɽ����ɽ����ɽ�������ǳ��������ڱ���Ұ��(yeteng)
�ڻΣ�����������ס��һ�㡣
LONG
        );
	set("item_desc", ([
		"yeteng" : "�⵹��һ��������Ұ�٣�������ʵ�ġ�\n",
    ]));

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="yeteng") {
                message("vision",
                me->name() + "˫��ץסҰ�٣���һ��ؾ�������ȥ��\n",
                environment(me), ({me}) );
                me->move(__DIR__"wulaoqiao");
                message("vision",
                me->name() + "������˳��Ұ�ٻ���������\n",
                environment(me), me );
                return 1;
        }
}
