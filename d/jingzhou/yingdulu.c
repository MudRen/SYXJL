
// Room: /jingzhou/yingdulu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "۫��·");
        set("long", @LONG
�˽ֵ����ɴ�ž�����Ϊԭ���������������ڴ˵�Ե�ʣ������ֽ���
�Ƚ�խ��������Ĳ�ݵ��в����������������е����飬������һ��ľ��
���̡�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"mujiangdian",
                "south" : __DIR__"huadian",
                "west"  : __DIR__"chaguan",
                "north" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}