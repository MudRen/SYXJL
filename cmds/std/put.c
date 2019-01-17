// put.c

// writed by shadow



inherit F_CLEAN_UP;



int do_put(object me, object obj, object dest);



void create() { seteuid(getuid()); }



int main(object me, string arg)

{

	string target, item;

	object obj, dest, *inv, obj2;

	int i, amount;



	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");



	if( sscanf(arg, "%s in %s", item, target)!=2 )

		return notify_fail("��Ҫ��˭ʲô������\n");



	dest = present(target, me);

	if( !dest || living(dest) ) dest = present(target, environment(me));

	if( !dest || living(dest) )

		return notify_fail("����û������������\n");



	if(sscanf(item, "%d %s", amount, item)==2) {

		if( !objectp(obj = present(item, me)) )

			return notify_fail("������û������������\n");

		if( !obj->query_amount() )

			return notify_fail( obj->name() + "���ܱ��ֿ���\n");

		if( amount < 1 )

			return notify_fail("����������������һ����\n");

		if( amount > obj->query_amount() )

			return notify_fail("��û����ô���" + obj->name() + "��\n");

		else if( amount == (int)obj->query_amount() )

			return do_put(me, obj, dest);

		else {

			obj->set_amount( (int)obj->query_amount() - amount );

			obj2 = new(base_name(obj));

			obj2->set_amount(amount);

			return do_put(me, obj2, dest);

		}

	}



	if(item=="all") {

		inv = all_inventory(me);

		for(i=0; i<sizeof(inv); i++)

			if( inv[i] != dest ) do_put(me, inv[i], dest);

		write("Ok.\n");

		return 1;

	}



	if(!objectp(obj = present(item, me)))

		return notify_fail("������û������������\n");

	if( (present(item, me))->query("no_put") )

		return notify_fail("�������������ҷš�\n");

	if( obj == dest )

		return notify_fail("�㲻�ܰѶ����Ž����Լ����档\n");



	return do_put(me, obj, dest);

}



int do_put(object me, object obj, object dest)

{

	if( obj->move(dest) )

	{

		if ( wizardp(me) || wizhood(me) == "(immortal)" )

		{

			log_file("static/wizput", sprintf("%s%s put %d %s %s in %s (%s)\n",

				me->query("name"),

				"(" + me->query("id") + ")" ,

				!obj->query_amount()?1:(int)obj->query_amount(),

				obj->query("unit"),

				base_name(obj) + ".c",

				base_name(dest) + ".c",

				ctime(time())

				) );

		}



		message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",

			obj->query("unit"), obj->name(), dest->name()),

			me );

		return 1;

	}

	else return 0;

}



int help(object me)

{

write(@HELP

ָ���ʽ : put <��Ʒ����> in <ĳ����>

 

���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��

 

HELP

    );

    return 1;

}

