inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��խխ��ʯ�ף��������˲�
����С�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shijie2",
  "eastdown" : __DIR__"baichi",
]));

        setup();
        replace_program(ROOM);
}
