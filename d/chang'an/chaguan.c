
// Room: /chang'an/chaguan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����
һ���ſ��������˿��ˣ������̸��ϷԺ���������ĳ�ǻ�����ͷ������
һЩ�����ϵ��¡�Ժ������һ��ˮ��(jing)��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}