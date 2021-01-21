
function create_fs() {
	while [ -n "$1" ]; do
		case $1 in
			

		esac	
		
	done

	if [ ! -d mnt ]; then
		mkdir mnt
		chown $USER mnt
	fi
	if [ ! -b /dev/ram0 ]; then	
		sudo modprobe brd
		sudo mkfs.ext2 /dev/ram0 -d
		
	fi
	sudo mount /dev/ram0 mnt
	sudo chown $USER mnt
	cd mnt
	git clone https://github.com/yoav-klein/repo.git
	cd ..
}

function create_class() {
	name=$1
	hname=${name}.h
	cppname=${name}.cpp
	capital=${name^}
	uppercase=${name^^}
	src_path=../src
	include_path=../include
	
	cd ./templates
	
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
