
// Room: /jingzhou/chaguan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ���̲�סҲ������������һ�¡�
���Ű�����һ���ſ��������˿��ˣ�������̨��˵��������ĭ��ɵؽ�����
���辣�ݵĹ��ϴ�˵����֪���ظ��ؽ��˶������ˡ���Ҫ����������ƹʺ�
ҥ�ԣ������Ǹ������ڡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"yingdulu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}