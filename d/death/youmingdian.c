inherit ROOM;

void create ()
{
  set ("short", "��ڤ��");
  set ("long", @LONG

��������������£����������ľ�����������ڤ������󶼻�
�������ܵ�Ӧ�еĴ��á���ǰһ�Ŵ�������ǰ����ڤ������˹��
ͳ�������ظ�������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youmingjie",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
]));
  setup();

}
