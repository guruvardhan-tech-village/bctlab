// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract TwoOrgNetwork {
    address public org1;
    address public org2;

    string public messageFromOrg1;
    string public messageFromOrg2;

    constructor(address _org2) {
        org1 = msg.sender; // Deployer = Org1
        org2 = _org2;      // Provide Org2 only
    }

    modifier onlyOrg1() {
        require(msg.sender == org1, "Not Org1");
        _;
    }

    modifier onlyOrg2() {
        require(msg.sender == org2, "Not Org2");
        _;
    }

    function sendMessageOrg1(string calldata _msg)
        external onlyOrg1 
    {
        messageFromOrg1 = _msg;
    }

    function sendMessageOrg2(string calldata _msg)
        external onlyOrg2 
    {
        messageFromOrg2 = _msg;
    }
}
