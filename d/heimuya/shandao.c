inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ����ɽ�����Ƽ�֮�վ���һ��խС���͵�ɽ��ͨ��ɽ�ϣ�����
ɽ����һƬ��̲��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"changtan",
  "westup" : __DIR__"shandao2",
]));

        setup();
        replace_program(ROOM);
}
