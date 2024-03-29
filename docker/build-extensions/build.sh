flavor=$1
mname=$2

repo=$3
branch=$4
if [ ! "$repo" ]; then
    repo="https://github.com/idaes/idaes-ext.git"
fi
if [ ! "$branch" ]; then
    branch="main"
fi

solver_buildargs=$5

echo "build.sh script arguments:
    OS: $flavor
    Arch: $mname
    Repo: $repo
    Branch: $branch
    Args to compile_solvers.sh: $solver_buildargs
"

if [ "$flavor" = "windows" ]; then
  image="idaes-ext-windows-build:latest"
  wdir="c:/repo"
elif [ "$flavor" = "el7" ]; then
  image="idaes-ext-el7-build:latest"
  wdir="/repo"
elif [ "$flavor" = "el8" ]; then
  image="idaes-ext-el8-build:latest"
  wdir="/repo"
elif [ "$flavor" = "ubuntu1804" ]; then
  image="idaes-ext-ubuntu1804-build:latest"
  wdir="/repo"
elif [ "$flavor" = "ubuntu2004" ]; then
  image="idaes-ext-ubuntu2004-build:latest"
  wdir="/repo"
elif [ "$flavor" = "ubuntu2204" ]; then
  image="idaes-ext-ubuntu2204-build:latest"
  wdir="/repo"
else
  echo "Specify flavor in {el7, el8, ubuntu1804, ubuntu2004, ubuntu2204, windows}."
  exit 1
fi


docker run --name "$flavor"_"$mname"_build_tmp -dt "$image"
docker cp ./extras/ "$flavor"_"$mname"_build_tmp:"$wdir"
docker exec "$flavor"_"$mname"_build_tmp sh -c "cp ${wdir}/extras/* ${wdir}"
docker exec "$flavor"_"$mname"_build_tmp sh -c "cd ${wdir}/extras && pwd"
docker exec "$flavor"_"$mname"_build_tmp sh -c "cd ${wdir} && git clone ${repo} && cd idaes-ext && git checkout ${branch}"
docker exec "$flavor"_"$mname"_build_tmp sh -c "cd ${wdir}/idaes-ext && bash scripts/compile_solvers.sh ${flavor} ${solver_buildargs}"
docker exec "$flavor"_"$mname"_build_tmp sh -c "cd ${wdir}/idaes-ext && bash scripts/compile_libs.sh ${flavor}"
docker stop "$flavor"_"$mname"_build_tmp

docker cp "$flavor"_"$mname"_build_tmp:"$wdir"/idaes-ext/dist-functions/idaes-functions-"$flavor"-"$mname".tar.gz .
docker cp "$flavor"_"$mname"_build_tmp:"$wdir"/idaes-ext/dist/idaes-solvers-"$flavor"-"$mname".tar.gz .

docker rm "$flavor"_"$mname"_build_tmp

mv *.tar.gz ./tarballs/
