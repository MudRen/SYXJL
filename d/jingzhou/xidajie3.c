
// Room: /jingzhou/xidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���ǿ����ֵĵط�����������Կ�����̨�����ǿ���ǧ����Ĵ�����
������һ��Ǯׯ������ȴ��һƬ�����������и���ߺ������������������
�������������Ž̵����ԭ��������һ�Ҷĳ���
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"huatai",
                "south" : __DIR__"duchang",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"qianzhuang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}