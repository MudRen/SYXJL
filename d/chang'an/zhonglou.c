
// Room: /chang'an/zhonglou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
������ǳ����е�������¥�ˡ��������ϱ�������ֽ��㴦��¥����
������һ�ڣ�ÿ�����ӱ�ʱ��������¥����¥����ʮ���ס����������ɻ�
����¥���¥����������ɣ������������Σ����濪ȯ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dongdajie3",
                "south" : __DIR__"nandajie2",
                "west"  : __DIR__"xidajie3",
                "north" : __DIR__"beidajie3",
                "up"    : __DIR__"zhonglouerceng",                             
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
