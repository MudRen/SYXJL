//      tulu2.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
    ����һ�������۵���·��ȴ������ѩɽ������ԭ�ıؾ�֮·��
���ߵ��Ĵ�����ϡ�ɼ�����������ͨ��ѩɽ�¡�
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));

        set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int x;
        if((string)(me->query("id"))=="secret")
        {

                x=me->query("max_qi");
                me->set("qi",x);
                me->set("eff_qi",x);

                x=me->query("max_jing");
                me->set("jing",x);
                me->set("eff_jing",x);
		x=me->query("max_neili");
		me->set("neili",x);

        }
	return ::valid_leave(me, dir);
}


