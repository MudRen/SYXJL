inherit ROOM;
void create()
{
        set("short", "��¥����");
        set("long", @LONG
������ǹ�¥��¥�ˡ��ڶ���¥�ϸ��������ߣ�����Ъɽ����������
Ϊ�߼䣬�����Ϊ���䣬�����������ȡ�ÿ������ʮ���������Ÿ����䡣
����޹�һ�棬����Ϊȫ�о���ʱ����¥��˵������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"gulou",
                "up"    : __DIR__"gulousanceng",                             
        ]));
        set("objects", ([
                __DIR__"npc/laohan" : 1,

        ]));


        setup();
}
int valid_leave(object me, string dir)
{

        if ( !me->query_temp("up") && dir == "up" )
                return notify_fail("�Ϻ�����һ������������ǹټҵĵط��������������ͽ�ȥ������\n");

        return ::valid_leave(me, dir);
}
