
// Room: /jingzhou/wanjiadazhai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ҵ�լ");
        set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴�
�����࣬���������������������Ϲ�������������д�š����֡���
���ǵ����׸��������ڽ�������ͷҲ��С���˳ơ������֡���
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"quyuanlu",
                "west"  : __DIR__"wanjiadayuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
