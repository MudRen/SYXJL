
// Room: /chang'an/dongdajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ������Ƕ��ڴ�֣�������һ���ֵ�����˵Ѳ
�����ͼ������������棬����ֱͨ�򳤰��ǵ������ţ������ɵ��������
����
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie1",
                "south" : __DIR__"shangdelu3",
                "west"  : __DIR__"dongdajie3",
                "north" : __DIR__"shangdelu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}