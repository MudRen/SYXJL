
// Room: /chang'an/xidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ���ܴ��ʮ
�ֽֿڡ������ǳ�����������¥��������һ��ר�ž�Ӫ�����ĵ��̣�����
�����ӵ��š������ǽ�����ۡ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"zhonglou",
                "south" : __DIR__"yuqihang",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"jiangjunfu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}