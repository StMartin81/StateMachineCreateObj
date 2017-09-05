import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true
        files: [
            "src/istatemachineevents.h",
            "src/main.cpp",
            "src/statemachine.cpp",
            "src/statemachine.h",
            "src/statemachinedata.h",
            "src/states.cpp",
            "src/states.h",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: product.type
            qbs.install: true
        }
    }
}
