
// Room: /jingzhou/jingnanlu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
�����·�治�Ǻܺã�·����һЩ������������һЩʯ�壬������׼
���Ľ��ˣ��ϱ���һ�ҳ����У����߲�ʱ���Կ���һЩ��ʹ���ſ������
������
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingnanlu2",
                "south" : __DIR__"chehang",
                "west"  : __DIR__"quyuanlu",
                "north" : __DIR__"yizhan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}