
// Room: /huoshan/dijiao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ؽ�");
        set("long", @LONG
�������ķ��䲻ͬ������Ĺ��ߺܰ�����ֻ��ǽ�ŵ�һյС��
��ȼ����Ծ�Ļ𻨣��յ����Ӱ��ҡ߮������˳��ǽһ��������
����һ���ŵ���ľ��Ͱ�����涼�Ǽ���������������ơ�
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "up"  : __DIR__"shiwu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}