//nongshe.c
inherit ROOM;

void create()
{
        set("short", "ũ��");
        set("long",
             "������һ��Сũ�ᣬ�Ҿߺ��¡��������˱Ƚϸ�ԣ��\n"
        );
        set("exits", ([
                "west" : __DIR__"guangchang",
        ]));
        set("objects",([
		__DIR__"npc/woman" : 1,
        ]));
        set("coor/x",-120);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-120);
	set("coor/y",-60);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
