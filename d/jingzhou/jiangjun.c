
// Room: /jingzhou/jiangjunfu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������˵ص��ر�����������լ���ſ�Ҳ��ʯʨ��Ҳû�š�����������
Ҫ��ͣ���������˾������ʣ��Է�ֹ�ɹ��˼������֣������ر�Ҳ��æ�ý�
ͷ�ö�������ѵ��ڼң����Ըɴ���Ž��գ�ֻ�������ױ����Ŵ��š�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"jingzhonglu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}