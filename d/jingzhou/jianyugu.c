
// Room: /jingzhou/jianyuguodao2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����һ���յ��η���ֻ���ŵ�������һ�����ɵݷ���С����������
����Ϣ���ֱ���Ů���ҡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"shilao",
                "west"  : __DIR__"silao",
                "north" : __DIR__"jianyuguodao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}