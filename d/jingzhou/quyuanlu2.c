
// Room: /jingzhou/quyuanlu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��ԭ·");
        set("long", @LONG
����ո�¹�����ʯ·���ϣ��о�˵���������ɣ���һ������������
������Ҫϡ��һЩ������ȴ���ü�һ��Сʳ̯����Ҳ��Щ���⡣��
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingnanlu",
                "south" : __DIR__"xiaoshitan",
                "north" : __DIR__"quyuanlu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}