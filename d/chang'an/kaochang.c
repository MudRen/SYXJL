// Room: /chang'an/kaochang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���߽����������ſ�����һ�顰�ྲ�������ӡ�һ���������ȽϺͰ�
������ʾ���������ﲻҪ������һ���࿼�����ڿ������Ϸ���һ�������ϣ�
�������´�������һ����
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}