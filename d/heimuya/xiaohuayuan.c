inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
ͻȻ�ŵ�һ���㣬�ؽ�Ϊ֮һˬ��������������һ�������µ�С��԰
�У���÷�������ɴ�أ����õü��߽��ģ�����������ԧ��������䣬
����һ�������о������ͷۺ��õ�壬�������ޣ�������ٱ��һ��
��ɽ֮�н��ż侫�ŵ�С�ᡣ
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"dedao",
		"west" : __DIR__"xiaoshe",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
