inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�㷢���Լ���һ���ʯ���棬�������գ�����������ɾ��ڣ��Ա���
һ��Сɽ����ƾ���ڵ���ۿ��Կ��ó����ɽ�������˹������ģ�����
��Լ͸����⡣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shandong",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
