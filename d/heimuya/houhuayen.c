inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�˴���������಻֪�����滨��ݣ��ھ���֮���������ľ�ɫ�������
Ʈ���ɾ��������ɻ����棬������һ��Сʯ�ݣ����ƺ�û���˾�ס��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jueya",
  "north" : __DIR__"changlang5",
  "west" : __DIR__"xiaosiwu",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhang" : 1,
  __DIR__"npc/lan" : 1,
]));

        setup();
        replace_program(ROOM);
}
