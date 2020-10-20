
function create_class() {
	name=$1
	hname=${name}.h
	cppname=${name}.cpp
	capital=${name^}
	uppercase=${name^^}
	src_path=../src
	include_path=../include
	
	cd ~/playground/file-systems/templates
	
	if [ -f $src_path/$cppname ]; then
		read -p "${cppname} already exists, override? Y/N" answer
	fi
	if [ ! -f $src_path/$cppname ] || [ $answer = "Y" ]; then
		cp template.cpp $cppname
		sed -i "s/template/${name}/" $cppname
		mv $cppname $src_path
	fi
	
	if [ -f $include_path/$hname ]; then
		read -p "${hname} already exists, override? Y/N" answer
	fi
	if [ ! -f $include/$hname ] || [ $answer = "Y" ]; then
		cp template.h $hname
		sed -i "s/TEMPLATE/${uppercase}/" $hname
		sed -i "s/Template/${capital}/" $hname
		mv $hname $include_path
	fi
	
	cd ../
}
