inherit ROOM;

void create()
{
        set("short", "�η����");
        set("long", @LONG
����һ�������ŵ����ţ����Ͽ��˸���������Ķ��ף��Ӷ�������ȥ��
�и�����ģ���������߶��š�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houdian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/da" : 1,
]));

        setup();
        replace_program(ROOM);
}
