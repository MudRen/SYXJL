
// Room: /chang'an/mahang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ǳ�������Ψһһ�ҳ����С���ɻ�һ��Ǯ����������������
ȥ���ܽ�Լ��������������Ȧ���Ų��ٵĺ���
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nandajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}