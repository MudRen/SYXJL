inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
Խ���ϣ�ɽ��Խ���ͣ��м��ʯ��Խխ������һ�����ߣ���������������
��Լ����һ��ʯ�š�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shimen",
  "eastdown" : __DIR__"shijie",
]));

        setup();
        replace_program(ROOM);
}
