inherit ROOM;

void create()
{
	set("short", "�����´��");
	set("long", @LONG
�����������ı����µĴ�̧ͷ��ȥ����һ��޴���������񣬸���
���������ǰ�������Ϲ�����������Ů�������������ı��ӡ������ǽ�̻�
�͵�����ľ�����ٱ��Ͼ����᷿�ˡ�ׯ�ϵ�����ʹ��Ҳ�����������뵽����
�Ϲ���(kneel)���Լ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"bgsgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
