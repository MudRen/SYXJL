
// Room: /chang'an/deshanglu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣������ɭɭ��ǽ����
���Ѻ���ڱ�Ͻ���ڷ������ﷸ�������ǳ����ǵı�Ӫ����������������
�����ľ�ʿ�ǵĲ�������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jianyu",
                "south" : __DIR__"dongdajie2",
                "west"  : __DIR__"bingyingdamen",
                "north" : __DIR__"deshanglu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}