inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
һ���ţ����ŵ�һ��Ũ�һ��㣬ֻ�����й���һ����Ůͼ��ͼ�л�����
����Ů������һ����ױ̨��̨��һ�������������廨���档�������ڻ�
�Ž��أ�֬��Ũ���˱ǣ�Ӧ���Ǽ�Ů�ӵĹ뷿��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xiaohuayuan",
]));
        set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/dongfang" : 1,
]));

        setup();
        replace_program(ROOM);
}
