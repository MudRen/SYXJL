// Room: /d/wuguan/woshi.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������ݹ��������ң����Ӳ����󣬺�������ӣ����ӵ�������
���룬���ӹ��������������߰���һ���辰��һ��С�������ż����顣
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"changlang4",
        ]));
        setup();
        replace_program(ROOM);
}
