
// Room: /jingzhou/nanmendajie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���Ŵ��");
        set("long", @LONG
�����Ǿ�����Ϊ�����ĵضΣ�·�ϵ��������ˣ��㲻�ɵ÷����Ų���
�У�������һ��ܴ�ġ����������ƣ��������Զ�Ϳ����ŵ�һ�ɴ̱ǵ�
ҩ��ζ����
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"dangpu",
                "south" : __DIR__"nanmendajie2",
                "west"  : __DIR__"yaopu",
                "north" : __DIR__"huatai",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}