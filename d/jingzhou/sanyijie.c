
// Room: /jingzhou/sanyijie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ֿ�����·�����룬�����Ǳ�����߹�ģ�ļ�Ժ�����治ʱ�ش�
��һ�����˵���Ц����������һ���ӻ��̣������湺����˿������١�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"zahuopu",
                "south" : __DIR__"huatai",
                "west"  : __DIR__"jiyuan",
                "north" : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}