
// Room: /jingzhou/shudian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
������һ����꣬���ڱ����˱Ƚ����ѧ�ߣ��ö���֮���ʢ�������
�����˸����鼮���㼸������������������Ҫ�ĸ����鼮��ǰ���������
���ﲻ�����ѹֹ��˷�������Ψ���вš��ĸ�̾�ˡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"kedian",
                "south" : __DIR__"guangchang",
                "west"  : __DIR__"qianzhuang",
                "north" : __DIR__"beidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}