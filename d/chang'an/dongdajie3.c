
// Room: /chang'an/dongdajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ����ʮ�ֽ�
�ڡ������ǳ���������㳡�������ǰ��ִ󿪵����Ŵ��ţ��ſ�վ�ż���
�����ɵ������ۣ�����ˮ���һ���������µ����ӡ����治ʱ�п������
������ԭ���Ǵ˴�����վ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie2",
                "south" : __DIR__"yizhan",
                "west"  : __DIR__"zhonglou",
                "north" : __DIR__"yamendamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}