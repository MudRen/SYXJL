inherit ROOM;

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
���а�����ʮ���޴����ܣ����Ϸ��������书�ؼ���������ؼ���
�ǽ��г�������������Ӹ�����֮��������������ģ����½��������
�ķ������ɴ˶������������������ɸ��ֶ��������ᰵ��������ľ��
����ɭ�ϣ����Ծ��޹�����������ÿ�ζ����˼��������ں�ľ���ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	        "down" : __DIR__"chengdedian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/lu" : 1,
		__DIR__"npc/shizhe" : 3,
]));

        setup();
        replace_program(ROOM);
}
